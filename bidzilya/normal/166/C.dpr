program Task3;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type integer = longint;
var ans,n,x,i: integer;
    a: array[1..500]of integer;
    ok: boolean;
    l,r,m: integer;

procedure qsort(l,r: integer);
var buf,x,i,j: integer;
begin
  i:=l;j:=r;x:=a[i+random(j-i+1)];
  repeat
    while (a[i]<x)do inc(i);
    while (a[j]>x)do dec(j);
    if (i<=j)then begin
      buf:=a[i];a[i]:=a[j];a[j]:=buf;
      inc(i);
      dec(j);
    end;
  until (i>j);
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;

begin
  read(n,x);

  ok:=false;
  for i:=1 to n do begin
    read(a[i]);
    if (a[i]=x)then
      ok:=true;
  end;
  ans:=0;
  if (not ok)then begin
    inc(n);
    a[n]:=x;
    inc(ans);
  end;
  qsort(1,n);
  for i:=1 to n do
    if (a[i]=x)then begin
      l:=i;
      break;
    end;
  for i:=n downto 1 do
    if (a[i]=x)then begin
      r:=i;
      break;
    end;
  m:=(n+1)div 2;
  while not ((m>=l)and(m<=r))do begin
    if (m>r)and(n mod 2=1)then
      dec(m);
    if (m<l)and(n mod 2=0)then
      inc(m);
    inc(ans);inc(n);
  end;
  write(ans);
end.