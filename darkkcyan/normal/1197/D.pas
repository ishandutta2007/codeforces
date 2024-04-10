{$mode objfpc}
uses math;
const maxn = 301010;
const maxm = 20;
const inf: int64 = 1000 * 1000 * 1000 * 1000 * 1000;
var
    n, k, m: longint;
    a: array[0..maxn] of int64;
    min_pref: array[0..maxm] of int64;
    pref, ans, s: int64;
    i, f: longint;

begin
    read(n, m, k);
    for i := 1 to n do begin
        read(a[i]);
        a[i] := a[i] * m - k;
    end;
    pref := 0;
    for i := 0 to m - 1 do min_pref[i] := inf;
    min_pref[0] := 0;
    ans := 0;

    for i := 1 to n do begin
        inc(pref, a[i]);

        for f := 0 to m - 1 do begin
            s := pref - min_pref[(i + m - f) mod m] - int64(k) * ((m - f) mod m);
            ans := max(ans, s);
        end;

        min_pref[i mod m] := min(min_pref[i mod m], pref);
    end;
    writeln(ans div m);
end.