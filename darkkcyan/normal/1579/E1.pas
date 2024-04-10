uses math;

const maxn = 202020;

var
    ntest: longint;
    n: longint;
    a: array[0..maxn] of longint;
    
    
type stack_t = record
    st: array[0..maxn] of longint;
    stl: longint;
end;

procedure push(var st: stack_t;  i: longint);
begin
    st.st[st.stl] := i;
    inc(st.stl);
end;

function pop(var st: stack_t): longint;
begin
    assert(st.stl > 0);
    dec(st.stl);
    exit(st.st[st.stl]);
end;

function top(var st: stack_t): longint;
begin
    exit(st.st[st.stl - 1]);
end;

var
    i: longint;
    min_stack, rest_stack: stack_t;
    
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        for i := 1 to n do begin
            read(a[i]);
        end;
        
        min_stack.stl := 0;
        rest_stack.stl := 0;
        
        push(min_stack, n + 1);
        
        for i := 1 to n do begin
            push(min_stack, min(top(min_stack), a[i]));
        end;
        
        for i := n downto 1 do begin
            if a[i] = top(min_stack) then write(a[i], ' ')
            else push(rest_stack, a[i]);
            pop(min_stack);
        end;
        while rest_stack.stl > 0 do begin
            write(pop(rest_stack), ' ');
        end;
        writeln;
    end;
end.