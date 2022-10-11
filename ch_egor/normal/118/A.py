def main():
    st = input()
    al = "aoyeui"
    st = st.lower()
    for i in al:
        st = st.replace(i, "", -1)

    st = list(st)
    print("."+".".join(st))

main()