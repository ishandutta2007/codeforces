const maxn = 1010101;
var
a: array[0..maxn] of longint;
p, cnt: array[0..maxn] of longint;
n, m, q: longint;
i, t, l, r: longint;

begin
    readln(n, m);
    q := 0;
    fillchar(a, sizeof(a), 0);
    a[0] := -(1 shl 30);
    for i := 1 to n do begin
        read(t);
        if a[q] <> t then begin
            inc(q);
            a[q] := t;
        end;
        p[i] := q;
    end;
    // for i := 1 to q do writeln(stderr, a[i]);
    a[q + 1] := 1 shl 30;
    fillchar(cnt, sizeof(cnt), 0);
    for i := 1 to q do begin
        cnt[i] := cnt[i - 1];
        if (a[i] < a[i - 1]) and (a[i] < a[i + 1]) then
            inc(cnt[i]);
    end;
    while m > 0 do begin dec(m);
        readln(l, r);
        l := p[l] + 1; r := p[r] - 1;
        if (l <= r) and (cnt[r] - cnt[l - 1] > 0) then writeln('No')
        else writeln('Yes');
    end;
end.