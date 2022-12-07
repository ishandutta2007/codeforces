for _ in range(int(input())):
    a, b, c = map(int, input().split())
    print(f"{max(0, max(b,c) - a + 1)} {max(0, max(a,c) - b+ 1)} {max(0, max(b,a) - c + 1)}")