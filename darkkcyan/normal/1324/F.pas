uses math;
const maxn = 401010;

var
    n: longint;
    col: array[0..maxn] of longint;
    val, next, head: array[0..maxn] of longint;
    cur_head: longint;
    
var 
    i: longint;
    u, v: longint;
    
    dp: array[0..maxn] of longint;
    
procedure dfs1(u, p: longint);
var
    i, v: longint;
begin
    i := head[u];
    dp[u] := col[u];
    while i <> -1 do begin
        v := val[i];
        i := next[i];
        if v = p then continue;
        dfs1(v, u);
        if dp[v] > 0 then inc(dp[u], dp[v]);
    end;
end;

var ans: array[0..maxn] of longint;
procedure dfs2(u, p, up_ans: longint);
var
    i, v: longint;
    pos_sum: longint;
begin
    // writeln(u, ' ', p, ' ', up_ans, ' ', dp[u]); 
    ans[u] := dp[u] + max(up_ans, 0);
    i := head[u];
    pos_sum := col[u] + max(up_ans, 0);
    while i <> -1 do begin
        v := val[i];
        i := next[i];
        if v = p then continue;
        if dp[v] > 0 then inc(pos_sum, dp[v]);
    end;
    
    i := head[u];
    while i <> -1 do begin
        v := val[i];
        i := next[i];
        if v = p then continue;
        if dp[v] > 0 then dec(pos_sum, dp[v]);
        dfs2(v, u, pos_sum);
        if dp[v] > 0 then inc(pos_sum, dp[v]);
    end;
end;

begin
    read(n);
    for i := 1 to n do begin
        read(col[i]);
        if col[i] = 0 then col[i] := -1;
    end;
    fillchar(head, sizeof(head), 255);
    cur_head := 0;
    for i := 1 to n - 1 do begin
        read(u, v);
        
        val[cur_head] := v;
        next[cur_head] := head[u];
        head[u] := cur_head;
        
        inc(cur_head);
        
        val[cur_head] := u;
        next[cur_head] := head[v];
        head[v] := cur_head;
        inc(cur_head);
    end;
    dfs1(1, 1);
    dfs2(1, 1, 0);
    
    for i := 1 to n do write(ans[i], ' ');
    // writeln; 
    // for i := 1 to n do write(dp[i], ' '); 
    
    
end.