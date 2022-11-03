program task_3;

{$APPTYPE CONSOLE}
const md = round(1e9)+7;
var dp: array[0..100,0..26*110]of integer;
    i,j,t,test: integer;
    s: string;
begin
  fillchar(dp,sizeof(dp),0);
  dp[0,0]:=1;
  for i:=1 to 100 do
    for j:=0 to 26*(i-1)do
      for t:=1 to 26 do
          dp[i,j+t]:=(dp[i,j+t]+dp[i-1,j])mod md;
  readln(test);
  for test:=1 to test do begin
      readln(s);
      t:=0;
      for i:=1 to length(s)do
          t:=t+ord(s[i])-ord('a')+1;
      j:=dp[length(s),t];
      dec(j);
      if (j<0)then j:=md;
      writeln(j);
  end;
end.