program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;
var n,k,m,i,j,b,free,ta,ind: integer;
    a1,a2,c,d: array[1..444]of integer;


procedure go(v1,v2: integer);
var buf: integer;
begin
  inc(ta);
  a1[ta]:=v1;
  a2[ta]:=v2;
  buf:=c[v1];c[v1]:=c[v2];c[v2]:=buf;
  buf:=d[v1];d[v1]:=d[v2];d[v2]:=buf;
end;

begin
  read(n,m);
  for i:=1 to n do begin
    c[i]:=maxint;
    d[i]:=i;
  end;
  for i:=1 to m do begin
    read(k);
    for j:=1 to k do begin
      read(b);
      c[b]:=i;
      d[b]:=j;
    end;
  end;
  ta:=0;

  for i:=1 to n do begin
    ind:=i;
    for j:=i+1 to n do
      if (c[j]<c[ind])or((c[j]=c[ind])and(d[j]<d[ind]))then
        ind:=j;
    if (ind=i)then
      continue;
    if (c[ind]=maxint)then
      break;
    for j:=i to n do
      if (c[j]=maxint)then
        free:=j;
    if (i<>free)then go(i,free);
    go(ind,i);
  end;
  writeln(ta);
  for i:=1 to ta do
    writeln(a1[i],' ',a2[i]);
end.