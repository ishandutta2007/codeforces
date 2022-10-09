uses math;

const maxval = 201010;
const maxn = 3030;
var bit: array[0..maxval] of longint;
procedure upd(pos: longint; val: longint);
begin
    inc(pos);
    while pos < maxval do begin
        bit[pos] := max(bit[pos], val);
        inc(pos, pos and -pos);
    end;
end;

procedure reset(pos: longint);
begin
    inc(pos);
    while pos < maxval do begin
        bit[pos] := 0;
        inc(pos, pos and -pos);
    end;
end;

function get(pos: longint): longint;
var ans: longint;
begin
    inc(pos);
    ans := 0;
    while pos > 0 do begin
        ans := max(ans, bit[pos]);
        dec(pos, pos and -pos);
    end;
    exit(ans);
end;

var ntest: longint;
var n: longint;
var l, r: array[0..maxn] of longint;
var i, f, g, temp, temp2, temp3: longint;

var dp: array[0..maxn] of longint;
var ans: longint;

begin
    read(ntest);
    fillchar(bit, sizeof(bit), 0);
    for ntest := 1 to ntest do begin
        // writeln(stderr);  
        read(n);
        for i := 1 to n do begin
            read(l[i], r[i]);
        end;
        
        for i := 1 to n do begin
            g := i;
            for f := i + 1 to n do begin
                if r[g] - l[g] > r[f] - l[f] then g := f;
            end;
            
            temp := l[i]; l[i] := l[g]; l[g] := temp;
            temp := r[i]; r[i] := r[g]; r[g] := temp;
        end;
        
        inc(n);
        l[n] := -3;
        r[n] := maxval - 1;
        
        ans := 0;
        for i := 1 to n do begin
            // for f := 1 to i - 1 do write(stderr, l[f], ' ', r[f], '; '); 
            // writeln(stderr); 
            for f := 1 to i - 1 do begin
                if (l[i] <= l[f]) and (r[f] <= r[i]) then  begin
                    upd(r[f], get(l[f] - 1) + dp[f]);
                end;
            end;
            
            dp[i] := get(r[i]) + 1;
            ans := max(ans, dp[i]);
            // writeln(stderr, l[i], ' ', r[i], ' ', dp[i]);   
            for f := 1 to i - 1 do 
                if (l[i] <= l[f]) and (r[f] <= r[i]) then reset(r[f]);
                
            temp := l[i];
            temp2 := r[i];
            temp3:= dp[i];
            g := i - 1;
            while (g > 0) and (l[g] > temp) do begin
                l[g + 1] := l[g];
                r[g + 1] := r[g];
                dp[g + 1] := dp[g];
                dec(g);
            end;
            
            inc(g);
            l[g] := temp;
            r[g] := temp2;
            dp[g] := temp3;
        end;
        writeln(ans - 1);
    end;
end.