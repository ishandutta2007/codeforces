const maxn = 3333;
begin
    var n: longint;
    read(n);
    
    var not_prime: array[0..maxn] of boolean;
    var n_prime_div: array[0..maxn] of integer;
    
    for var i := 2 to n do begin
        if not_prime[i] then continue;
        foreach var f in range(i, n, i) do n_prime_div[f] += 1;
        foreach var f in range(2 * i, n, i) do not_prime[f] := true;
    end;
    
    var ans := 0;
    for var i := 1 to n do 
        if n_prime_div[i] = 2 then ans += 1;
    
    writeln(ans);
    
end.