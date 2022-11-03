var
  n,m,i:integer;
  
begin
  read(n,m);
  i:=1;
  while m>=i do begin
    m:=m-i;
    inc(i);
    if i>n then i:=1;
  end;
  write(m);
end.