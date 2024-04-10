uses math;

var ntest: longint;
var n: longint;
var a, b: array[0..100] of longint;
var min_a, min_b: longint;
var i: longint;
var ans: int64;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        min_a := 1000 * 1000 * 1000 + 10;
        min_b := min_a;
        for i := 1 to n do begin
            read(a[i]);
            min_a := min(min_a, a[i]);
        end;
        
        for i := 1 to n do begin
            read(b[i]);
            min_b := min(min_b, b[i]);
        end;
        
        ans := 0;
        for i := 1 to n do begin
            inc(ans, max(a[i] - min_a, b[i] - min_b));
        end;
        writeln(ans);
    end;
end.