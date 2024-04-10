uses math;
var a,dp: array[0..100000] of int64;
     n,x,mn: int64;
     i,j: longint;
    Begin
      Read(n);
      For i:=1 to n do
          begin
            Read(x);
            if x>mn then mn:=x;
            inc(a[x]);
          end;
      dp[1]:=a[1];
      dp[0]:=0;
      For i:=2 to mn do
           dp[i]:=max(dp[i-1],dp[i-2]+(a[i]*i));
                    Write(dp[mn]);
    End.