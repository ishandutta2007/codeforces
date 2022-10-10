uses math;

const maxn = 111 * 2;
const rem = 1000 * 1000 * 1000 + 7;

function add(u: longint; v: longint): longint;
begin
    inc(u, v);
    if u >= rem then dec(u, rem);
    exit(u);
end;

function sub(u: longint; v: longint): longint;
begin
    dec(u, v);
    if u < 0 then inc(u, rem);
    exit(u);
end;

function mul(u: longint; v: longint): longint;
begin
    mul := longint((int64(u) * int64(v)) mod rem);
end;

var choose: array[0..maxn, 0..maxn] of longint;

procedure precal;
var i, f: longint;
begin
    fillchar(choose, sizeof(choose), 0);
    for i := 0 to maxn do begin
        choose[i][0] := 1;
        for f := 1 to i do 
            choose[i][f] := add(choose[i - 1][f], choose[i - 1][f - 1]);
    end;
end;

var
    ntest: longint;
    n: longint;
    head: array[0..maxn] of longint;
    next: array[0..maxn] of longint;
    ver: array[0..maxn] of longint;
    cur_head: longint;

var depth: array[0..maxn] of longint;
var dp: array[0..maxn, 0..maxn] of longint;
var cnt_depth: array[0..maxn] of longint;
    
procedure dfs(u: longint; p: longint);
var
    it: longint;
    v: longint;
begin
    depth[u] := depth[p] + 1;
    inc(cnt_depth[depth[u]]);
    it := head[u];
    while it <> -1 do begin
        v := ver[it];
        it := next[it];
        if v = p then continue;
        dfs(v, u);
    end;
end;

var k: longint;
var i, f, it, u, v, d: longint;
var ans: longint;

begin
    precal();
    read(ntest);
    fillchar(cnt_depth, sizeof(cnt_depth), 0);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        read(k);
        for i := 1 to n do begin
            head[i] := -1;
        end;
        cur_head := 0;
        for i  := 1 to n - 1 do begin
            read(u, v);
            
            next[cur_head] := head[u];
            ver[cur_head] := v;
            head[u] := cur_head;
            inc(cur_head);
            
            next[cur_head] := head[v];
            ver[cur_head] := u;
            head[v] := cur_head;
            inc(cur_head);
        end;
        
        if k = 2 then begin
            writeln(n * (n - 1) div 2);
            continue;
        end;
        
        ans := 0;
        for i := 1 to n do begin
            fillchar(dp, sizeof(dp), 0);
            for f := 0 to n do dp[0][f] := 1;
            it := head[i];
            depth[i] := 0;
            while it <> -1 do begin
                u := ver[it];
                it := next[it];
                dfs(u, i);
                for d := 1 to n do begin
                    if cnt_depth[d] = 0 then break;
                    for f := k downto 1 do begin
                        dp[f][d] := add(dp[f][d], mul(dp[f - 1][d], cnt_depth[d]));
                    end;
                    cnt_depth[d] := 0;
                end;
            end;
            
            for d := 0 to n do ans := add(ans, dp[k][d]);
        end;
        writeln(ans);
    end;
end.