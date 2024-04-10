var
   L, b , f, r, n, len, q , w, z, tek, i, j : longint;
   fa : boolean;
   s : array[-300..300000] of longint;
   ans, leng : array[0..100] of longint;
begin
   read(L,b,f);
   b := b ;
   f := f ;

   read(n);
   L := L + f - 1;
   R := -b;
   for i := 1 to n do
   begin
      read(z);
      if z = 2 then
      begin
         read(j);
         for q := ans[j] to ans[j] + leng[j] - 1 do
            S[q] := 0;
      end;
      if z = 1 then
      begin
         read(len);
         q := r;
         fa := true;
         while (q <= l) do
         begin
            if s[q] = 0 then
            begin
               tek := 1;
               j := q + 1;
               while (s[j] = 0) and (j <= l) do
               begin
                  inc(tek);
                  inc(j);
               end;
               dec(j);
               if tek >= len + f + b  then
               begin
                  fa := false;
                  ans[i] := q + b;             {!}
                  leng[i] := len;
                  for w := q + b to q + b + len - 1  do
                     s[w] := 1;
                  break;
               end;
               q := j;
            end;
            inc(q);
         end;
         if fa then ans[i] := -1;
         writeln(ans[i]);
      end;
   end;
end.