uses math;

const maxn = 5010;

var
    n: longint;
    i, f, g: longint;
    left_side: array[0..maxn, -maxn..maxn] of boolean;
    cnt: array[0..4] of longint;
    pos: array[0..4, 0..maxn] of longint;
    x, y: longint;
    a, c: ansistring;
    
begin
    readln(n);
    readln(c);
    readln(a);
    
    fillchar(cnt, sizeof(cnt), 0);
    
    for i := 1 to n do begin
        f := (ord(c[i]) - ord('0')) * 2 + (ord(a[i]) - ord('0'));
        inc(cnt[f]);
        pos[f][cnt[f]] := i;
    end;
    
    // writeln(stderr, cnt[0]); 
    // writeln(stderr, cnt[1]); 
    // writeln(stderr, cnt[2]); 
    // writeln(stderr, cnt[3]); 
    
    for i := 0 to maxn do for f := -maxn to maxn do begin
        left_side[i][f] := false;
        
    end;
    
    for i := 0 to cnt[0] do begin
        for f := 0 to cnt[1] do begin
            left_side[i + f][-(cnt[1] - f)] := true;
            // writeln(stderr, i, ' ', f, ' ', -(cnt[1] - f)); 
        end;
    end;
    
    // writeln(stderr); 
    for i := 0 to cnt[2] do begin
        for f := 0 to cnt[3] do begin
            if n div 2 - i - f < 0 then continue;
            if not left_side[n div 2 - i - f][cnt[3] - (i + 2 * f)] then continue;
            
            for g := 1 to i do begin
                write(pos[2][g], ' ');
            end;
            for g := 1 to f do begin
                write(pos[3][g], ' ');
            end;
            
            for x := 0 to cnt[0] do begin
                y := n div 2 - i - f - x;
                if (y < 0) or (y > cnt[1]) then continue;
                if -(cnt[1] - y) <> cnt[3] - (i  + 2 * f) then continue;
                
                for g := 1 to x do begin
                    write(pos[0][g], ' ');
                end;
                for g := 1 to y do begin
                    write(pos[1][g], ' ');
                end;
                halt;
            end;
        end;
    end;
    writeln('-1');
    
end.