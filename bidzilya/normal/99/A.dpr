var
  s:string;
  p:integer;
begin
  readln(s);
  p:=pos('.',s);
  if s[p-1]='9' then writeln('GOTO Vasilisa.') else
    if s[p+1]<'5' then writeln(copy(s,1,p-1)) else
      begin
        write(copy(s,1,p-2));
        write(chr(ord(s[p-1])+1));
      end;
end.