var 
  s:String;
  k,l,i,sm:integer;
  
begin
  k:=0;
  sm:=0;
  while not eof do begin
    readln(s);
    if s[1]='+' then inc(k) else
      if s[1]='-' then dec(k) else begin
        i:=1;
        while s[i]<>':' do inc(i);
        l:=length(s)-i;
        sm:=sm+(k*l);
      end;
  end;
  write(sm);
end.