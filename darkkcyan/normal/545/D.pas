uses math;
const maxn = 101010;

var temp: array[0..maxn] of longint;
procedure sort(var arr: array of longint);
var mid, u, v, i: longint;
begin
    if length(arr) <= 1 then exit();
    mid := length(arr) div 2;
    sort(arr[0..mid - 1]);
    sort(arr[mid..high(arr)]);
    for u := 0 to high(arr) do temp[u] := arr[u];
    
    v := mid;
    i := 0;
    for u := 0 to mid - 1 do begin
        while (v < length(arr)) and (temp[v] < temp[u]) do begin
            arr[i] := temp[v];
            inc(i);
            inc(v);
        end;
        arr[i] := temp[u];
        inc(i);
    end;
    for v := v to high(arr) do begin
        arr[i] := temp[v];
        inc(i);
    end;
end;

var a: array[0..maxn] of longint;
var n: longint;
var prev_sum: int64;
var i, ans: longint;
begin
    read(n);
    for i := 1 to n do read(a[i]);
    sort(a[1..n]);
    prev_sum := 0;
    ans := 0;
    for i := 1 to n do begin
        if (a[i] >= prev_sum) then begin
            inc(ans);
            inc(prev_sum, a[i]);
        end;
    end;
    writeln(ans);
end.