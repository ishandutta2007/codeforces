var
  g:Array[1..200,1..200]of longint;
  ans:array[1..200]of longint;
  i,j,tot,n:longint;
function judge(x:longint):boolean;
var
  i:longint;
begin
  for i:=1 to n do
    if i<>x then
    begin
      if g[x,i]=1 then exit(false);
      if g[x,i]=3 then exit(false);
    end;
  exit(true);
end;
begin

  read(n);
  for i:=1 to n do
    for j:=1 to n do read(g[i,j]);
  tot:=0;
  for i:=1 to n do
    if judge(i) then
    begin
      inc(tot);
      ans[tot]:=i;
    end;
  writeln(tot);
  if tot=0 then
  begin
  end
  else
  begin
    write(ans[1]);
    for i:=2 to tot do write(' ',ans[i]);
    writeln;
  end;

end.