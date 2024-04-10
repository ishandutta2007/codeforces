var s:string;
i:longint;
BEGIN
  readln(s);
  
  for i:= 1 to length(s) do
  begin
    if(i = 1) and (s[i] >= 'a') and (s[i] <= 'z') then write(chr(ord(s[i]) + ord('A') - ord('a')))
      else write(s[i]);
  end;
END.