uses math;

const maxn = 5010;

var
    n: longint;
    a, c, dp: array[0..maxn] of longint;
    b: array[0..maxn] of boolean;
    i, f, g, cnt: longint;

begin
    read(n);
    fillchar(c, sizeof(c), 0);
    for i := 1 to n do begin
        read(a[i]);
        inc(c[a[i]]);
    end;
    fillchar(dp, sizeof(dp), 0);
    for i := 1 to n do begin
        dp[i] := dp[i - 1];
        fillchar(b, sizeof(b), 0);
        g := 0;
        cnt := 0;
        for f := i downto 1 do begin
            if not b[a[f]] then begin
                g := g xor a[f];
                inc(cnt, c[a[f]]);
                b[a[f]] := true;
            end;
            dec(cnt);
            if cnt = 0 then dp[i] := max(dp[i], dp[f - 1] + g);
        end;
    end;
    //for i := 1 to n do writeln(stderr, i,' ', dp[i]);
    writeln(dp[n]);

end.