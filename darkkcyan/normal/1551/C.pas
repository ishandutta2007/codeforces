uses math;

const maxn = 201010;

var dt: array[0..maxn] of longint;
procedure sort(var a: array of longint);
var mid, i, f, g: longint;
begin
    if length(a) <= 1 then exit();
    mid := (length(a) - 1) div 2;
    sort(a[0..mid]);
    sort(a[mid + 1 .. high(a)]);
    
    for i := low(a) to high(a) do dt[i] := a[i];
    
    f := 0;
    g := 0;
    for i := mid + 1 to high(a) do begin
        while (f <= mid) and (dt[f] < dt[i]) do begin
            a[g] := dt[f];
            inc(g);
            inc(f);
        end;
        a[g] := dt[i];
        inc(g);
    end;
    for i := f to mid do begin
        a[g] := dt[i];
        inc(g);
    end;
end;


const oa = ord('a');
var ntest: longint;
var n: longint;
var cnt: array[0..maxn, 0..5] of longint;
var ln: array[0..maxn] of longint;
var a: array[0..maxn] of longint;

function solve(ch: byte): longint;
var i: longint;
var ans: longint;
var sum: longint;
begin
    // writeln(stderr, 'ch = ', ch); 
    for i := 1 to n do begin
        a[i] := 2 * cnt[i][ch] - ln[i];
        // write(stderr, a[i], ':', ln[i], ' '); 
    end;
    // writeln(stderr); 
    sort(a[1..n]);
    // for i := 1 to n do write(stderr, a[i], ' '); 
    // writeln(stderr); 
    ans := 0;
    sum := 0;
    
    for i := n downto 1 do begin 
        if sum + a[i] <= 0 then break;
        inc(ans);
        inc(sum, a[i]);
    end;
    // writeln(stderr, ch,' ', ans); 
    exit(ans);
end;

var i, f: longint;
var s: ansistring;
var ans: longint;

begin
    readln(ntest);
    while ntest > 0 do begin
        // writeln(stderr, ' ===== '); 
        dec(ntest);
        readln(n);
        for i := 1 to n do begin
            readln(s);
            ln[i] := length(s);
            for f := 0 to 4 do cnt[i][f] := 0;
            for f := 1 to length(s) do begin
                inc(cnt[i][ord(s[f]) - oa]);
            end;
        end;
        
        ans := 0;
        for i := 0 to 4 do begin
            ans := max(ans, solve(i));
        end;
        writeln(ans);
    end;
end.