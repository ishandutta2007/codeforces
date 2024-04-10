uses Math;
var n,m,t,i,j:integer;
    ans:int64;
    C:array[0..30,0..30]of int64;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m,t);
  ans:=0;
  for i:=0 to 30 do
  begin
    C[i,0]:=1;
    C[i,i]:=1;
    for j:=1 to i do
      C[i,j]:=C[i-1,j-1]+C[i-1,j];
  end;
  for i:=4 to min(n,t-1) do
    if t-i<=m then
      ans:=ans+C[n,i]*C[m,t-i];
  write(ans);
end.