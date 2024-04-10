begin
    var a, b: string;
    readln(a);
    readln(b);
    
    var cnt1b := 0;
    for var i := 1 to length(b) do 
        cnt1b += byte(b[i] = '1');
        
    var ans := 0;
    var cur_cnt1 := 0;
    
    for var i := 1 to length(a) do begin
        cur_cnt1 += byte(a[i] = '1');
        if i >= length(b) then begin
            ans += 1 - (cnt1b + cur_cnt1) mod 2;
            cur_cnt1 += byte(a[i - length(b) + 1] = '1');
        end;
    end;
    write(ans);
end.