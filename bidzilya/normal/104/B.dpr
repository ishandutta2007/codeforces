var
  n,i:integer;
  sm:int64;
  a:array[1..100]of integer;
  
begin
  sm:=0;
  read(n);
  for i:=1 to n do 
    read(a[i]);
  i:=1;
  while i<=n do begin
    sm:=sm+1;
    dec(a[i]);
    sm:=sm+int64((i-1))*int64(a[i]);
    sm:=sm+a[i];
    inc(i);
  end;
  write(sm);
end.