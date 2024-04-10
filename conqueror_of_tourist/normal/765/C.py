a, b, c = map(int, input().split())

out = b//a + c//a

if b//a == 0 and c % a:
    print(-1)
elif c//a == 0 and b % a:
    print(-1)
else:
    print(out)