uses Math;
type t = array[-1..2000] of longint;
const inf = -10000000000000;
var
   a : array[-1..2000] of t;
   b,sum,ans,maxv,maxn : array[-1..2000,-1..2000] of int64;
   c : t;
   ma : int64;
   i, j, n, tek,  m, bal, minn : longint;
begin               {
   assign(input,'input.txt');
   assign(output,'output.txt');
   reset(input);
   rewrite(output) ;   }
   read(n,m);
   for i := 1 to n do
      for j := 1 to m do
         read(a[i,j]);
   for i := 1 to n do
   begin
      sum[i,0] := 0;
      for j := 1 to m do
         sum[i,j] := sum[i,j-1] + a[i,j];
   end;
   for j :=2 to m do
      ans[1,j] := sum[1,j];
   ans[1,1] := inf;
   maxv[1,m+1] := inf;
    maxv[1,m] := ans[1,m];
      for j := m - 1 downto 1 do
         maxv[1,j] := max(maxv[1,j+1],ans[1,j]);
   for i := 2 to n do
   begin
      if (i mod 2 = 0) then
      begin
         for j := 1 to m-1 do
            ans[i,j] := sum[i,j] + maxv[i-1,j+1];
         maxn[i,0] := inf;
         ans[i,m] := inf;
         maxn[i,1] := ans[i,1];
         for j := 2 to m do
            maxn[i,j] := max(maxn[i,j-1],ans[i,j]);
      end;
      if (i mod 2 = 1) then
      begin
         for j := 2 to m do
            ans[i,j] := sum[i,j] + maxn[i-1,j-1];
         maxv[i,m+1] := inf;
         ans[i,1] := inf;
         maxv[i,m] := ans[i,m];
         for j := m - 1 downto 1 do
            maxv[i,j] := max(maxv[i,j+1],ans[i,j]);
      end;
   end;
   ma := inf;
   for j := 1 to m do
      ma := max(ans[n,j],ma);
   write(ma);      {
   close(output); }
end.