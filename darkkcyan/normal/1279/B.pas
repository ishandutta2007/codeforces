uses math;

const maxn = 101010;
var
    ntest: longint;
    n, s: longint;
    a: array[0..maxn]of int64;

function find_pos(cur_s: longint; var pref_sum: array of int64): longint;
var
    l, r, mid: longint;
begin
    l := low(pref_sum);
    r := high(pref_sum);
    if pref_sum[r] - pref_sum[l] <= cur_s then exit(r);
    while r - l > 1 do begin
        mid := l + (r - l) div 2;
        if pref_sum[mid] - pref_sum[low(pref_sum)] <= cur_s then l := mid
        else r := mid;
    end;
    exit(l);
end;

var
    i: longint;
    cur_ans, ans, opt: longint;
begin
    read(ntest);
    while (ntest > 0) do begin
        dec(ntest);
        read(n, s);
        for i := 1 to n do read(a[i]);
        a[0] := 0;
        for i := 1 to n do inc(a[i], a[i - 1]);

        if (s >= a[n]) then begin
            writeln(0);
            continue;
        end;

        ans := 0;
        opt := 1;
        for i := 1 to n do begin
            if s < a[i - 1] then break;
            cur_ans := i - 1 + find_pos(s - a[i - 1], a[i..n]);
            // writeln(stderr, i, ' ', cur_ans);
            if cur_ans <= ans then continue;
            ans := cur_ans;
            opt := i;
        end;
        writeln(opt);
    end;
end.