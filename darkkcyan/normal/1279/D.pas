uses math;

const rem: int64 = 998244353;
const maxn = 1010101;
var
    n, m: longint;
    want: array[0..maxn] of longint;
    present: array[0..maxn] of longint;
    pick_prob: array[0..maxn] of int64;

function mpow(base: int64; exp: int64): int64;
var ans: int64 = 1;
begin
    while exp > 0 do begin
        if (exp and 1) = 1 then ans := (ans * base) mod rem;
        base := (base * base) mod rem;
        exp := exp shr 1;
    end;
    exit(ans);
end;

var ans: int64;
var k, i, f: longint;
var inv_n, inv_k: int64;
begin
    read(n);
    inv_n := mpow(n, rem - 2);
    m := 0;
    fillchar(want, sizeof(want), 0);
    for i := 1 to n do begin
        read(k);
        inv_k := mpow(k, rem - 2);
        for f := 1 to k do begin
            read(present[m + f]);
            pick_prob[m + f] := inv_n * inv_k mod rem;
            inc(want[present[m + f]]);
        end;
        inc(m, k);
    end;

    ans := 0;
    for i := 1 to m do begin
        ans := (ans + pick_prob[i] * inv_n mod rem * want[present[i]] mod rem) mod rem;
    end;
    writeln(ans);
end.