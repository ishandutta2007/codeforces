uses math;
const maxn = 201010;
var
    ntest: longint;
    n: longint;
    a: array[0..maxn] of longint;
    
function thickness(arr: array of longint; part_sum: int64): longint;
var
    l, r: longint;
    cur_sum: int64;
    ans: longint;
begin
    l := 0;
    r := 0;
    ans := 0;
    while l < length(arr) do begin
        cur_sum := 0;
        for r := l to high(arr) do begin
            inc(cur_sum, arr[r]);
            if cur_sum >= part_sum then break;
        end;
        if cur_sum > part_sum then exit(length(arr));
        inc(r);
        if ans < r - l then ans := r - l;
        l := r;
    end;
    exit(ans);
end;

var
    sum_all: int64;
    i: longint;
    cur_sum: int64;
    ans: longint;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 0 to n - 1 do read(a[i]);
        
        sum_all := 0;
        for i := 0 to n - 1 do inc(sum_all, a[i]);
        ans := n;
        
        cur_sum := 0;
        for i := 0 to n - 1 do begin
            inc(cur_sum, a[i]);
            if (sum_all mod cur_sum = 0) then begin
                ans := min(ans, thickness(a[0..n - 1], cur_sum));
            end;
        end;
        writeln(ans);
    end;
end.