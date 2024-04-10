uses math;

const maxn = 2010100;
var
    ntest: longint;
    n, d: longint;
    a: array[0..maxn] of longint;
    vis: array[0..maxn] of boolean;
    b: array[0..maxn] of longint;
    bl: longint;
    
function min_res_chain: longint;
var
    i, first0, u: longint;
    ans: longint;
    cur_cnt1: longint;
begin
    first0 := 0;
    while (first0 < bl) and (b[first0] = 1) do inc(first0);
    if first0 = bl then exit(-1);
    
    cur_cnt1 := 0;
    ans := 0;
    for i := 0 to bl - 1 do begin
        u := (i + first0) mod bl;
        if (b[u] = 1) then begin
            inc(cur_cnt1);
            continue;
        end;
        ans := max(ans, cur_cnt1);
        cur_cnt1 := 0;
    end;
    ans := max(ans, cur_cnt1);
    exit(ans);
end;

var
    i, f: longint;
    ans, x: longint;
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        // writeln(stderr, '==='); 
        read(n, d);
        d := (n - d mod n) mod n;
        for i := 0 to n - 1 do read(a[i]);
        for i := 0 to n - 1 do vis[i] := false;
        ans := 0;
        for i := 0 to n - 1 do begin
            if vis[i] then continue;
            // writeln(stderr, '##', i); 
            f := i;
            bl := 0;
            while not vis[f] do begin
                // write(stderr, f, ' '); 
                b[bl] := a[f];
                inc(bl);
                vis[f] := true;
                f := (f + d) mod n;
            end;
            // writeln(stderr); 
            x := min_res_chain;
            if x = -1 then begin
                ans := -1;
                break;
            end;
            ans := max(ans, x);
        end;
        writeln(ans);
    end;
end.