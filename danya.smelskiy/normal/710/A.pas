var s1: string;
 Begin
  Readln(s1);
  if (s1='a1') or (s1='a8') or (s1='h1') or (s1='h8') then Write('3')
  else if (s1[1]='a') or (s1[1]='h') or (s1[2]='8') or (s1[2]='1') then Write('5')
  else Write('8');
 End.