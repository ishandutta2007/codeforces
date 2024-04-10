var
  a:array[1..100] of boolean;
  n,m:Integer;
  k,i,j,x:Integer;
begin
  readln(n,m);
  for i:=1 to m do
    a[i]:=false;
  for i:=1 to n do
  begin
    read(k);
    for j:=1 to k do
    begin
      read(x);
      a[x]:=true;
    end;
    readln;
  end;
  for i:=1 to m do
  begin
    if a[i]=false then
    begin
      write('NO');
      halt(0);
    end;
  end;
  write('YES');
end.