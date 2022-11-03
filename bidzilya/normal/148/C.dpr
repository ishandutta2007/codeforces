program C;

{$APPTYPE CONSOLE}
var n,a,b,t: integer;
begin
  read(n,a,b);
  if (b=0)and(a<>0)and(a+2>n)then begin
    write(-1);
    halt;
  end;
  write(1,' ');
  if (b=0)and(a<>0)then begin
    write(1,' ');
    dec(n);
  end;
  t:=1;
  dec(n);
  while (b>0)do begin
    t:=t*2;
    write(t,' ');
    dec(b);
    dec(n);
  end;
  while (a>0)do begin
    inc(t);
    write(t,' ');
    dec(a);
    dec(n);
  end;
  while (n>0)do begin
    write(1,' ');
    dec(n);
  end;
end.