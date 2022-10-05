import random
u, v, p = map(int, input().split())

TRIALS = 10 ** 4
LENGTH = 25

ans = []
for i in range(TRIALS):
    for curr, t in ((u, 0), (v, 1)):
        seed = random.randint(0, (1<<LENGTH) - 1)
        so = seed
        for i in range(LENGTH):
            if seed % 2:
                curr = pow(curr, p - 2, p)
            else:
                curr += 1
            seed //= 2
        ans.append((curr, so, t))

ans.sort(key = lambda x:x[0])

for i in range(2 * TRIALS - 1):
    if ans[i + 1][0] - ans[i][0] < 200 - 2 * LENGTH:
        if ans[i + 1][2] != ans[i][2]:
            if ans[i + 1][2]:
                v_seed = ans[i + 1][1]
                v_val = ans[i + 1][0]
                u_seed = ans[i + 0][1]
                u_val = ans[i + 0][0]
            else:
                u_seed = ans[i + 1][1]
                u_val = ans[i + 1][0]
                v_seed = ans[i + 0][1]
                v_val = ans[i + 0][0]
                
            #print(u_val, v_val)

            out = []
            out_r = []
            for i in range(LENGTH):
                if u_seed % 2:
                    out.append(3)
                else:
                    out.append(1)
                u_seed //= 2

            for i in range(LENGTH):
                if v_seed % 2:
                    out_r.append(3)
                else:
                    out_r.append(2)
                v_seed //= 2

            while u_val != v_val:
                if u_val < v_val:
                    u_val += 1
                    out.append(1)
                else:
                    u_val -= 1
                    out.append(2)

            out_t = out + out_r[::-1]
            """for op in out_t:
                if op == 1:
                    u += 1
                elif op == 2:
                    u -= 1
                else:
                    u = pow(u, p - 2, p)
                print(op, u)"""
            print(len(out_t))
            print(' '.join(map(str,out_t)))
            break