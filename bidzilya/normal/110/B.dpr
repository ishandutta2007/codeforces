var
  i,n:integer;
  
begin
  read(n);
  for i:=1 to n do
    write(chr((i-1) mod 4+97));
end.