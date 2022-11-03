var
  s,ts:String;
  i,j:integer;
  
begin
  readln(s);
  ts:='hello';
  i:=1;
  j:=1;
  while (j<=5)and(i<=length(s)) do begin
    if s[i]=ts[j] then inc(j);
    inc(i);
  end;
  if j=6 then writeln('YES') else writeln('NO');
end.