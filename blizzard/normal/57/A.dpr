uses Math;
var
   n, x1, x2, y1,y2 : longint;
procedure return(a : longint);
begin
  writeln(a);
  halt(0);
end;
begin
   read(n,x1,y1,x2,y2);
   if (x1 = x2) and ((x1 = 0) or (x1 = n)) then return(abs(y1-y2));
   if (y1 = y2) and ((y1 = 0) or (y1 = n)) then return(abs(x1-x2));
   if ((x1 = n) and (x2 = 0)) or ((x1 = 0) and (x2 = n)) then return(min(y1 + n + y2, (n - y1) + n + (n - y2)));
   if ((y1 = n) and (y2 = 0)) or ((y1 = 0) and (y2 = n)) then return(min(x1 + n + x2, (n - x1) + n + (n - x2)));
   if (y1 = n) then
   begin
      if x2 = n then return(n - x1 + n - y2);
      if x2 = 0 then return(n - y2 + x1);
   end;
   if (y2 = n) then
   begin
      if x1 = n then return(n - x2 + n - y1);
      if x1 = 0 then return(n - y1 + x2);
   end;
   if (y1 = 0) then
   begin
      if x2 = n then return(y2 + (n - x1));
      if x2 = 0 then return(y2 + x1);
   end;
   if (y2 = 0) then
   begin
      if x1 = n then return(y1 + (n - x2));
      if x1 = 0 then return(y1 + x2);
   end;
   halt(1);
end.