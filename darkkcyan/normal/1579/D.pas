uses math;

const maxn = 201010;

var
    ntest: longint;
    n: longint;
    a: array[0..maxn] of longint;
    
var 
    heap: array[0..maxn] of longint;
    heap_length: longint;
    
procedure swap(var x, y: longint);
var tmp: longint;
begin
    tmp := x;
    x := y;
    y := tmp;
end;
    
procedure push_down(i: longint);
var 
    mx: longint;
begin
    if i >= heap_length then exit();
    mx := i;
    if (2 * i + 1 < heap_length) and (a[heap[mx]] < a[heap[2 * i + 1]]) then 
        mx := 2 * i + 1;
    if (2 * i + 2 < heap_length) and (a[heap[mx]] < a[heap[2 * i + 2]]) then 
        mx := 2 * i + 2;
    if mx = i then exit;
    swap(heap[i], heap[mx]);
    push_down(mx);
end;

procedure pull_up(i: longint);
begin
    if i = 0 then exit;
    if a[heap[i]] <= a[heap[(i - 1) div 2]] then exit;
    swap(heap[i], heap[(i - 1) div 2]);
    pull_up((i - 1) div 2);
end;

function pop(): longint;
var ans: longint;
begin
    assert(heap_length > 0);
    dec(heap_length);
    ans := heap[0];
    swap(heap[0], heap[heap_length]);
    push_down(0);
    exit(ans);
end;

procedure push(x: longint);
begin
    inc(heap_length);
    heap[heap_length - 1] := x;
    pull_up(heap_length - 1);
end;

var
    i, u, v: longint;
    ans_cnt: longint;
    ans_u, ans_v: array[0..maxn * 2] of longint;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do read(a[i]);
        heap_length := 0;
        for i := 1 to n do if a[i] > 0 then push(i);
        
        ans_cnt := 0;
        while heap_length >= 2 do begin
            u := pop();
            v := pop();
            inc(ans_cnt);
            ans_u[ans_cnt] := u;
            ans_v[ans_cnt] := v;
            dec(a[u]);
            dec(a[v]);
            if a[u] > 0 then push(u);
            if a[v] > 0 then push(v);
        end;
        writeln(ans_cnt);
        for i := 1 to ans_cnt do begin
            writeln(ans_u[i], ' ', ans_v[i]);
        end;
    end;
end.