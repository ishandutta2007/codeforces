var
    k,r,ans:^longint;
begin
    new(k);
    new(r);
    new(ans);
    read(k^,r^);
    ans^:=1;
    while (k^*ans^ mod 10<>r^) and (k^*ans^ mod 10<>0) do ans^:=ans^+1;
    writeln(ans^)
end.