{$h+}
var
   s1,s2 : string;
   i,j : longint;
   f : boolean;
begin
   readln(s1);
   readln(s2);
   for i := 1 to length(s2) do
   begin
      if s2[i] = ' ' then continue;
      f := true;
      for j := 1 to length(s1) do
         if s1[j] = s2[i] then
         begin
            f := false;
            delete(s1,j,1);
            break;
         end;
      if f then
      begin
         write('NO');
         halt(0);
      end;
   end;
   write('YES');
end.