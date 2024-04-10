uses math;
var
  n,m,x,i,j,ans:longint;
begin
  readln(n,m); ans:=4;
  for i:=1 to n do
  for j:=1 to m do
  begin
    read(x);
    if ((i=1)or(i=n))and((j=1)or(j=m))and(x=1) then ans:=1;
    if ((i=1)or(i=n)or(j=1)or(j=m))and(x=1) then ans:=min(ans,2);
  end;
  writeln(ans);
end.