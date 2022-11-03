program C;

{$APPTYPE CONSOLE}
uses SysUtils;
var name,name2:array[1..3000]of string;
    k,t,tmp,a,ans:array[1..3000]of integer;
    len,tt,all,n,i,p,j:integer;
    s:string;

procedure qsort(l,r:integer);
var x:integer;
begin
  i:=l; j:=r; x:=a[(i+j)div 2];
  repeat
    while (a[i]<x)do inc(i);
    while (a[j]>x)do dec(j);
    if (i<=j)then begin
      s:=name[i];
      name[i]:=name[j];
      name[j]:=s;
      p:=a[i]; a[i]:=a[j];
      a[j]:=p;
      inc(i); dec(j);
    end;
  until i>j;
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;

procedure insert(v:integer);
var i:integer;
begin
  tt:=a[v]+1;
  
  for i:=len downto tt do
  begin
    t[i+1]:=t[i];
    name2[i+1]:=name2[i];
  end;
  inc(len);
  dec(all);
  t[tt]:=all;
  name2[tt]:=name[v];
end;

begin
  readln(n);
  for i:=1 to n do begin
    readln(s);
    p:=pos(' ',s);
    name[i]:=copy(s,1,p-1);
    a[i]:=strtoint(copy(s,p+1,length(s)-p));
  end;
  all:=n+1;
  len:=0;
  qsort(1,n);
  for i:=1 to n do
    if (a[i]>i-1)then begin write(-1); halt; end else insert(i);
  for i:=1 to n do
    writeln(name2[i],' ',t[i]);
end.