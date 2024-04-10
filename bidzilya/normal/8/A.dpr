program project1;

{$apptype console}

uses Math, SysUtils;
type arr = array[0..222222]of integer;
var s,s1,s2: string;
    l,i,n,r: integer;
    ok1,ok2: boolean;
    p: arr;

procedure reverse(var s: string);
var i,j: integer;
    buf: char;
begin
  for i:=1 to length(s)div 2 do begin
    j:=length(s)-i+1;
    buf:=s[j];
    s[j]:=s[i];
    s[i]:=buf;
  end;
end;

procedure prefix(text,obr: string;var a: arr;var n: integer);
var i,j: integer;
    s: string;
begin
  s:=obr+'#'+text;
  n:=length(s);
  a[1]:=0;
  j:=0;
  for i:=2 to n do begin
    while (j<>0)and(s[j+1]<>s[i])do j:=a[j];

    if (s[j+1]=s[i])then inc(j);
    a[i]:=j;
  end;
end;

begin
  readln(s);
  readln(s1);
  readln(s2);
  prefix(s,s1,p,n);
  r:=-1;
  for i:=length(s1)+2 to n do
    if (p[i]=length(s1))then begin
      r:=i-length(s1)-1;
      break;
    end;
  prefix(s,s2,p,n);
  l:=-1;
  for i:=n downto length(s2)+2 do
    if (p[i]=length(s2))then begin
      l:=i-2*length(s2);
      break;
    end;
  ok1:=(l<>-1)and(r<>-1)and(l>r);

  reverse(s);

  prefix(s,s1,p,n);
  r:=-1;
  for i:=length(s1)+2 to n do
    if (p[i]=length(s1))then begin
      r:=i-length(s1)-1;
      break;
    end;
  prefix(s,s2,p,n);
  l:=-1;
  for i:=n downto length(s2)+2 do
    if (p[i]=length(s2))then begin
      l:=i-2*length(s2);
      break;
    end;
  ok2:=(l<>-1)and(r<>-1)and(l>r);

  if (ok1)and(ok2)then
    writeln('both')
  else
  if (ok1)then
    writeln('forward')
  else
  if (ok2)then
    writeln('backward')
  else
    writeln('fantasy');
end.