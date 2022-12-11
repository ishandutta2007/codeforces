program Almost_Identity_Permutations;

const
   maxn = 1003;
   maxk = 4;

var
   n, k: longint;
   ans: int64;

begin
   readln(n, k);

   ans := 1;
   if k >= 2 then inc(ans, int64(n) * (n - 1) div 2);
   if k >= 3 then inc(ans, int64(n) * (n - 1) * (n - 2) div 6 * 2);
   if k >= 4 then inc(ans, int64(n) * (n - 1) * (n - 2) * (n - 3) div 24 * 9);

   writeln(ans);
end.