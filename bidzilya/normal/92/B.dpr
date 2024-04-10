var
  s:String;
  sm,l:integer;
begin
  readln(s);
  sm:=0;
  l:=length(s);
  while s[l]='0' do begin inc(sm); delete(s,l,1); dec(l); end;
  if l=1 then begin if s='0' then inc(sm); write(sm); halt; end;
  while l>1 do begin    
    inc(sm);
    while (l>=1)and(s[l]='1') do begin delete(s,l,1); inc(sm); dec(l); end;
    if l=0 then s:='1'+s else s[l]:='1';
  end;
  write(sm);
end.