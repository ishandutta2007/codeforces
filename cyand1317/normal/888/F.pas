program Connecting_Vertices;

const
   maxn = 504;
   modulus = 1000000007;

var
   n: longint;
   a: array [1 .. maxn, 1 .. maxn] of longint;

   i, j, k, len: longint;
   {
      f[l, r] - number of ways to connect vertices in [l, r] into a tree
      g[l, r] - number of ways, but l and r are already connected
      h[l, r] - number of ways to connect each vertex to either l or r
   }
   f, g, h: array [1 .. maxn, 1 .. maxn] of int64;

begin
   readln(n);
   for i := 1 to n do
      for j := 1 to n do read(a[i, j]);

   fillchar(f, sizeof(f), 0);
   fillchar(g, sizeof(g), 0);
   fillchar(h, sizeof(h), 0);
   for i := 1 to n do f[i, i] := 1;
   for i := 1 to n do g[i, i] := 1;
   for i := 1 to n do h[i, i] := 1;

   for len := 2 to n do
      for i := 1 to n - len + 1 do begin
         j := i + len - 1;
         { Calculate g[i, j] }
         if a[i, j] = 1 then begin
            g[i, j] := f[i + 1, j];
            for k := i + 1 to j - 1 do if a[i, k] = 1 then
               g[i, j] := (g[i, j] + g[i, k] * h[k, j]) mod modulus;
         end;
         { Calculate f[i, j] }
         for k := i + 1 to j do if a[i, k] = 1 then
            f[i, j] := (f[i, j] + g[i, k] * f[k, j]) mod modulus;
         { Calculate h[i, j] }
         for k := i to j - 1 do
            h[i, j] := (h[i, j] + f[i, k] * f[k + 1, j]) mod modulus;
      end;

   writeln(f[1, n]);
end.