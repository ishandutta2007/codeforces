var
  n:integer;

begin
  read(n);
  n:=n-10;
  if ((n>=1)and(n<=9))or(n=11)then write('4') else
    if (n<=0)or(n>=12) then write('0') else
      if n=10 then write('15');

end.