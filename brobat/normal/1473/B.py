def func():
    s = input()
    t = input()
    u = 0
    for i in range(1,21):
        for j in range(1,21):
            if u==0 and s*i==t*j:
                print(s*i)
                u = 1
                break
    if u==0:
        print(-1)

for _ in range(int(input())):
    func()