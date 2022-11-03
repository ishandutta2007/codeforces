program A;

{$APPTYPE CONSOLE}

var a1,a2,a3,a4,r1,r2,c1,c2,d1,d2:integer;
begin
  read(r1,r2,c1,c2,d1,d2);
  for a1:=1 to 9 do
    for a2:=1 to 9 do
      for a3:=1 to 9 do
        for a4:=1 to 9 do
          if (a1<>a2)and(a1<>a3)and(a1<>a4)and(a2<>a3)and(a2<>a4)and(a3<>a4)and
             (a1+a2=r1)and(a3+a4=r2)and
             (a1+a3=c1)and(a2+a4=c2)and
             (a1+a4=d1)and(a2+a3=d2)then begin
              writeln(a1,' ',a2);
              writeln(a3,' ',a4);
              halt;
             end;
  writeln(-1);
end.