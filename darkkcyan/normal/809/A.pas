const maxn = 300101;
const rem: longint = 1000 * 1000 * 1000 + 7;
var temp: array[0..maxn] of int64;
procedure sort(var a: array of int64);
var
    mid, l, r, i: longint;
begin
    if length(a) <= 1 then exit();
    mid := (low(a) + high(a)) div 2;
    sort(a[low(a) .. mid]);
    sort(a[mid + 1 .. high(a)]);
    for i := low(a) to high(a) do temp[i] := a[i];
    
    l := low(a); r := mid + 1; i := low(a);
    while (l <= mid) and (r <= high(a)) do begin
        if temp[l] < temp[r] then begin
            a[i] := temp[l];
            inc(l);
        end else begin
            a[i] := temp[r];
            inc(r);
        end;
        inc(i);
    end;
    while l <= mid do begin
        a[i] := temp[l];
        inc(l); inc(i);
    end;
    while r <= high(a) do begin
        a[i] := temp[r];
        inc(r); inc(i);
    end;
end;

var p2: array[0..maxn] of int64;
procedure cal_p2();
var i: longint;
begin
    p2[0] := 1;
    for i := 1 to maxn do p2[i] := p2[i - 1] * 2 mod rem;
end;

var n: longint;
var a: array[0..maxn] of int64;
var i: longint;
var ans: int64;
begin
    cal_p2();
    read(n);
    for i := 1 to n do read(a[i]);
    sort(a[1..n]);
    ans := 0;
    for i := 1 to n do begin
        inc(ans, a[i] * p2[i - 1]);
        ans := ans mod rem;
        inc(ans, (rem - a[i]) * p2[n  - i]);
        ans := ans mod rem;
    end;
    write(ans);
end.