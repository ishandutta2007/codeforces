{$apptype console}
var
   i,n,k, ob, max : longint;
   f, fa : boolean;
   a,b : array[0..1000] of longint;
begin
   read(n);
   f := true;
   for i := 1 to n do read(a[i]);
   k := 0;
   for i := 1 to n do
      if a[i] < 0 then
      begin
        inc(k);
        b[k] := a[i];
      end;
   for i := 1 to n do
      if a[i] > 0 then
      begin
         write(a[i],' ');
         f := false;
      end;
   repeat
      fa := true;
      for i := 1 to k-1 do
         if b[i] > b[i+1] then
         begin
            ob := b[i];
            b[i] := b[i+1];
            b[i+1] := ob;
            fa := false;
         end;
   until fa;
   for i := 1 to (k div 2) * 2 do
   begin
      write(b[i],' ');
      f := false;
   end;
   if f then
   begin
      max := 1-maxlongint;
      for i := 1 to n do
         if a[i] > max then max := a[i];
      write(max);
   end;
end.