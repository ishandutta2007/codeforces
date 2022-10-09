uses math;

const maxn = 2020;
const inf = 10101010;
var
    ntest: longint;
    n, k: longint;
    a: array[0..maxn] of longint;
    
    dp: array[0..maxn] of longint;
    
var 
    i, f, u, v: longint;
    ans: longint;

begin
    read(ntest);
    while ntest > 0 do begin
        // writeln(stderr, '======'); 
        dec(ntest);
        read(n, k);
        for i := 1 to n do read(a[i]);
        
        ans := inf;
        for i := 1 to n do begin
            u := i - a[i];
            dp[i] := byte(u >= 0);
            // writeln(stderr, i, ' ', u, ' ', dp[i]); 
            if u < 0 then continue;
            for f := i - 1 downto 1 do begin
                v := f - a[f];
                // writeln(stderr, '* ', f, ' ', v, ' ', (i - f - 1), ' ', dp[f]); 
                if v < 0 then continue;
                if v > u then continue;
                if (u - v) <= i - f - 1 then begin
                    dp[i] := max(dp[i], dp[f] + 1);
                    // writeln(stderr, '<-', f, ' ', dp[f]);  
                end;
            end;
            // writeln(stderr, dp[i]); 
            if dp[i] >= k then ans := min(ans, u);
        end;
        if ans >= inf then writeln(-1)
        else writeln(ans);
        
    end;
end.