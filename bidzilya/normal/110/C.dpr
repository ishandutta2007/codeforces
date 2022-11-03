var
  ost,i,n,k7,k4:integer;
  
procedure show;
begin
  write('-1');
  halt;
end;
  
begin
  read(n);
  k4:=0;
  k7:=n div 7;
  ost:=n mod 7;
  if (ost>=1)and(ost<=3)then begin
    if k7>=ost then begin
      k7:=k7-ost;
      k4:=ost*2;
    end else show;
  end else if ost=4 then k4:=1 else
    if (ost=5)or(ost=6)then begin
      k4:=1;
      ost:=ost-4;
      if k7>=ost then begin
        k7:=k7-ost;
        k4:=k4+ost*2;
      end else show;
    end;

  for i:=1 to k4 do
   write('4');
  for i:=1 to k7 do
   write('7');
end.