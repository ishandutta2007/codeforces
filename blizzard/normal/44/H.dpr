var
   s : string;
   i,j,n : longint;
   sum : int64;
   sr : extended;
   a : array[0..1000,0..1000] of int64;
   f : boolean;
begin
   readln(s);
   n := length(s);
   for j := 0 to 9 do
      a[1,j] := 1;
   for i := 2 to n do
   begin
      for j := 0 to 9 do
      begin
         sr := (j + (ord(s[i]) - 48)) / 2;
         if sr <> trunc(sr) then
         begin
            a[i,trunc(sr)] := a[i,trunc(sr)] + a[i-1,j];
             a[i,trunc(sr) + 1] := a[i,trunc(sr) + 1] + a[i-1,j];
         end else
            a[i,trunc(sr)] :=  a[i,trunc(sr)] + a[i-1,j];
      end;
   end;
   sum := 0;
   for j := 0 to 9 do
      sum := sum + a[n,j];
   f := true;
   for i := 2 to n do
     begin
       sr := ord(s[i]) - 48 + ord(s[i - 1]) - 48;
       sr := sr / 2;
       if sr = round(sr) then
         if (trunc(sr) <> ord(s[i]) - 48) then f := false;

       if sr <> round(sr) then
         if (trunc(sr) <> ord(s[i]) - 48)
         and (trunc(sr) + 1 <> ord(s[i]) - 48)
         then f := false;
     end;
   if f then dec(sum);
   write(sum);
end.