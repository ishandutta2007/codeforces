uses math;

const maxn = 10101;
const maxval = 1010 * 2;
const inf = maxval * maxval;

var
    ntest: longint;
    n: longint;
    a: array[0..maxn] of longint;
    dp: array[0..2, 0..maxval] of longint;
    i, f: longint;
    cur: longint;
    ans: longint;
    
    
procedure upd_dp(i, pos, val: longint);
begin
    if (pos < 0) or (pos > maxval) then exit();
    dp[i and 1][pos] := min(dp[i and 1][pos], val);
end;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do begin
            read(a[i]);
        end;
        
        for i := 0 to maxval do dp[1][i] := inf;
        
        dp[1][a[1]] := 0;
        for i := 2 to n do begin
            for f := 0 to maxval do dp[i and 1][f] := inf;
            for f := 0 to maxval do begin
                cur := dp[1 - (i and 1)][f];
                if cur >= inf then continue;
                upd_dp(i, max(0, f - a[i]), cur + a[i]);
                upd_dp(i, f + a[i], max(cur - a[i], 0));
            end;
            // writeln(stderr, 'i = ', i); 
            // for f := 0 to maxval do begin 
                // if dp[i and 1][f] >= inf then continue; 
                // write(stderr, f, ':', dp[i and 1][f], ' '); 
            // end; 
            // writeln(stderr); 
        end;
        ans := inf;
        for i := 0 to maxval do begin
            ans := min(ans, dp[n and 1][i] + i);
        end;
        writeln(ans);
    end;
end.