{$mode objfpc}
uses math;

const maxn = 301010;
const inf: int64 = 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 100;
var
    q, n: longint;
    a, b: array[0..maxn] of int64;
    dp: array[0..maxn, 0..2] of int64;
    i, f, g: longint;
    temp: int64;

begin
    readln(q);
    while q > 0 do begin
        dec(q);
        readln(n);
        for i := 1 to n do readln(a[i], b[i]);
        dp[1][0] := 0;
        dp[1][1] := b[1];
        dp[1][2] := 2 * b[1];
        
        for i := 2 to n do begin
            dp[i][0] := inf;
            dp[i][1] := inf;
            dp[i][2] := inf;
            for f := 0 to 2 do 
            for g := 0 to 2 do begin
                if dp[i - 1][g] = inf then continue;
                temp := dp[i - 1][g] + f * b[i];
                if (a[i] + f = a[i - 1] + g) then
                    continue;
                dp[i][f] := min(dp[i][f], temp);
            end;
        end;
        writeln(min(min(dp[n][0], dp[n][1]), dp[n][2]));
    end;
end.