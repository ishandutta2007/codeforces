var
  n,i,a,b:integer;
  d:array[2..100] of integer;
  
begin
  read(n);
  for i:=2 to n do
    read(d[i]);
  read(a,b);
  n:=0;
  for i:=a+1 to b do
    n:=n+d[i];
  write(n);
end.