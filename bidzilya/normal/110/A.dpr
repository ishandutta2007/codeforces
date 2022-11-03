var
  k,c:integer;
  n:int64;
  
begin
  read(n);
  k:=0;
  
  while n>0 do begin
    c:=n mod 10;
    n:=n div 10;
    if (c=4)or(c=7)then inc(k);
  end;
  
  if k=0 then begin
    write('NO');
    halt;
  end;
  while k>0 do begin
    c:=k mod 10;
    k:=k div 10;
    if (c<>4)and(c<>7)then begin
      write('NO');
      halt;
    end;
  end;
  write('YES');
end.