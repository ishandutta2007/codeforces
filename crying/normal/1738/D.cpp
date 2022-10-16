__asm__(R"(
	.file	"E.cpp"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB863:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	xorl	%ebx, %ebx
.L3:
	leaq	2400096+in(%rip), %rax
	movq	(%rax,%rbx), %rcx
	testq	%rcx, %rcx
	je	.L2
	call	_ZdlPv
.L2:
	subq	$24, %rbx
	cmpq	$-2400120, %rbx
	jne	.L3
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.section	.text$_Z4Readv,"x"
	.linkonce discard
	.globl	_Z4Readv
	.def	_Z4Readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Readv
_Z4Readv:
.LFB772:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$1, %esi
	orl	$-1, %edi
.L10:
	call	getchar
	leal	-48(%rax), %edx
	movb	%al, %bl
	cmpb	$9, %dl
	jbe	.L20
	cmpb	$45, %al
	cmove	%edi, %esi
	jmp	.L10
.L20:
	xorl	$48, %ebx
	movsbl	%bl, %ebx
.L17:
	call	getchar
	leal	-48(%rax), %edx
	cmpb	$9, %dl
	ja	.L21
	leal	(%rbx,%rbx), %edx
	xorl	$48, %eax
	leal	(%rdx,%rbx,8), %edx
	movsbl	%al, %ebx
	addl	%edx, %ebx
	jmp	.L17
.L21:
	movl	%ebx, %eax
	imull	%esi, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_Z5printi,"x"
	.linkonce discard
	.globl	_Z5printi
	.def	_Z5printi;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5printi
_Z5printi:
.LFB773:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	cmpl	$9, %ecx
	movl	%ecx, %ebx
	jle	.L23
	movl	%ebx, %eax
	movl	$10, %ecx
	cltd
	idivl	%ecx
	movl	%eax, %ecx
	call	_Z5printi
.L23:
	movl	%ebx, %eax
	movl	$10, %ecx
	cltd
	idivl	%ecx
	leal	48(%rdx), %ecx
	addq	$32, %rsp
	popq	%rbx
	jmp	putchar
	.seh_endproc
	.section	.text$_Z5Printic,"x"
	.linkonce discard
	.globl	_Z5Printic
	.def	_Z5Printic;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5Printic
_Z5Printic:
.LFB774:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	testl	%ecx, %ecx
	movl	%ecx, %ebx
	movl	%edx, %esi
	jns	.L25
	movl	$45, %ecx
	negl	%ebx
	call	putchar
.L25:
	movl	%ebx, %ecx
	call	_Z5printi
	movsbl	%sil, %ecx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	jmp	putchar
	.seh_endproc
	.section	.text$_Z5Solvev,"x"
	.linkonce discard
	.globl	_Z5Solvev
	.def	_Z5Solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5Solvev
_Z5Solvev:
.LFB777:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	n(%rip), %eax
	leaq	cnt(%rip), %rdx
	movq	%rdx, %r8
	leal	1(%rax), %ecx
	movslq	%ecx, %rcx
	movl	(%rdx,%rcx,4), %ecx
.L28:
	movslq	%eax, %rdx
	decl	%eax
	cmpl	%ecx, %edx
	je	.L38
	addl	(%r8,%rdx,4), %ecx
	jmp	.L28
.L38:
	movl	$10, %edx
	movl	%ecx, k(%rip)
	call	_Z5Printic
	movl	n(%rip), %r9d
	leaq	in(%rip), %rcx
	leaq	ans(%rip), %r11
	movl	$0, m(%rip)
	leal	1(%r9), %edx
	movslq	%edx, %rax
	imulq	$24, %rax, %rax
	addq	%rcx, %rax
	movq	8(%rax), %r8
	subq	(%rax), %r8
	movq	%r8, %rax
	shrq	$2, %rax
	movl	$0, %eax
	cmove	%eax, %edx
	movl	%edx, ans(%rip)
.L32:
	movslq	m(%rip), %rax
	cmpl	%r9d, %eax
	jge	.L39
	movslq	(%r11,%rax,4), %rax
	leaq	ans(%rip), %rbx
	xorl	%r10d, %r10d
	imulq	$24, %rax, %rax
	leaq	(%rcx,%rax), %rdx
	movq	8(%rdx), %r8
	subq	(%rdx), %r8
	sarq	$2, %r8
.L33:
	cmpq	%r8, %r10
	je	.L32
	movl	m(%rip), %esi
	leal	1(%rsi), %edx
	movq	(%rcx,%rax), %rsi
	movl	%edx, m(%rip)
	movslq	%edx, %rdx
	movl	(%rsi,%r10,4), %esi
	incq	%r10
	movl	%esi, (%rbx,%rdx,4)
	jmp	.L33
.L39:
	xorl	%ebx, %ebx
.L36:
	leal	1(%rbx), %eax
	incq	%rbx
	cmpl	n(%rip), %eax
	jg	.L40
	leaq	ans(%rip), %rax
	movl	$32, %edx
	movl	(%rax,%rbx,4), %ecx
	call	_Z5Printic
	jmp	.L36
.L40:
	movl	$10, %ecx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	jmp	putchar
	.seh_endproc
	.section	.text$_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_:
.LFB808:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	8(%rcx), %rbx
	subq	(%rcx), %rbx
	movq	%rcx, %rdi
	movq	%rdx, %rbp
	movq	%rbx, %rax
	movl	$1, %ebx
	sarq	$2, %rax
	cmovne	%rax, %rbx
	addq	%rax, %rbx
	jc	.L54
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %rbx
	jbe	.L43
.L54:
	movabsq	$4611686018427387903, %rbx
.L50:
	leaq	0(,%rbx,4), %rcx
	call	_Znwy
	movq	%rax, %rsi
.L51:
	movq	8(%rdi), %r8
	movq	(%rdi), %rcx
	movl	0(%rbp), %edx
	movq	%r8, %rax
	subq	%rcx, %rax
	addq	%rsi, %rax
	je	.L45
	movl	%edx, (%rax)
.L45:
	movq	%rcx, %rdx
	movq	%rsi, %rax
.L46:
	cmpq	%r8, %rdx
	je	.L66
	testq	%rax, %rax
	movl	(%rdx), %r9d
	je	.L55
	movl	%r9d, (%rax)
.L55:
	addq	$4, %rax
	addq	$4, %rdx
	jmp	.L46
.L66:
	subq	%rcx, %rdx
	andq	$-4, %rdx
	testq	%rcx, %rcx
	leaq	4(%rsi,%rdx), %rbp
	je	.L49
	call	_ZdlPv
.L49:
	leaq	(%rsi,%rbx,4), %rax
	movq	%rsi, (%rdi)
	movq	%rbp, 8(%rdi)
	movq	%rax, 16(%rdi)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L43:
	xorl	%esi, %esi
	testq	%rbx, %rbx
	je	.L51
	jmp	.L50
	.seh_endproc
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.section	.text$_Z4Initv,"x"
	.linkonce discard
	.globl	_Z4Initv
	.def	_Z4Initv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Initv
_Z4Initv:
.LFB776:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	_Z4Readv
	leaq	in(%rip), %rdx
	movl	%eax, n(%rip)
	xorl	%ecx, %ecx
	incl	%eax
	movq	%rdx, %rbx
.L68:
	cmpl	%ecx, %eax
	jl	.L88
	leaq	cnt(%rip), %r8
	addq	$24, %rdx
	movl	$0, (%r8,%rcx,4)
	movq	-24(%rdx), %r8
	incq	%rcx
	movq	%r8, -16(%rdx)
	jmp	.L68
.L88:
	leaq	44(%rsp), %rsi
	movl	$1, 44(%rsp)
.L70:
	movslq	44(%rsp), %rdi
	cmpl	n(%rip), %edi
	jg	.L89
	call	_Z4Readv
	leaq	b(%rip), %r8
	leaq	cnt(%rip), %rcx
	movl	%eax, (%r8,%rdi,4)
	movslq	44(%rsp), %rax
	movq	%rax, %rdx
	movslq	(%r8,%rax,4), %rax
	incl	(%rcx,%rax,4)
	imulq	$24, %rax, %rcx
	addq	%rbx, %rcx
	movq	8(%rcx), %r8
	cmpq	16(%rcx), %r8
	je	.L71
	testq	%r8, %r8
	je	.L72
	movl	%edx, (%r8)
.L72:
	imulq	$24, %rax, %rax
	addq	$4, %r8
	movq	%r8, 8(%rbx,%rax)
	jmp	.L73
.L71:
	movq	%rsi, %rdx
	call	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
.L73:
	incl	44(%rsp)
	jmp	.L70
.L89:
	xorl	%ecx, %ecx
.L75:
	movl	n(%rip), %eax
	incl	%eax
	cmpl	%eax, %ecx
	jg	.L90
	movslq	%ecx, %rdx
	imulq	$24, %rdx, %rdx
	addq	%rbx, %rdx
	movq	8(%rdx), %rax
	subq	(%rdx), %rax
	sarq	$2, %rax
	je	.L76
	imulq	$24, %rcx, %rdi
	xorl	%r8d, %r8d
.L77:
	cmpq	%rax, %r8
	je	.L76
	movq	(%rbx,%rdi), %rsi
	leaq	(%rsi,%r8,4), %r11
	incq	%r8
	movslq	(%r11), %rdx
	movq	%rdx, %r10
	imulq	$24, %rdx, %rdx
	addq	%rbx, %rdx
	movq	8(%rdx), %r9
	subq	(%rdx), %r9
	movq	%r9, %rdx
	shrq	$2, %rdx
	je	.L77
	leaq	-4(%rsi,%rax,4), %rax
	movl	(%rax), %edx
	movl	%edx, (%r11)
	movl	%r10d, (%rax)
.L76:
	incq	%rcx
	jmp	.L75
.L90:
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB778:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	call	_Z4Readv
	movl	%eax, T(%rip)
.L92:
	cmpl	$0, T(%rip)
	je	.L94
	call	_Z4Initv
	call	_Z5Solvev
	decl	T(%rip)
	jmp	.L92
.L94:
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_n;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_n
_GLOBAL__sub_I_n:
.LFB864:
	.seh_endprologue
	leaq	in(%rip), %rax
	leaq	2400120+in(%rip), %rdx
.L96:
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	addq	$24, %rax
	movq	$0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L96
	leaq	__tcf_0(%rip), %rcx
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_n
	.globl	T
	.bss
	.align 4
T:
	.space 4
	.globl	m
	.align 4
m:
	.space 4
	.globl	ans
	.align 64
ans:
	.space 400020
	.globl	k
	.align 4
k:
	.space 4
	.globl	cnt
	.align 64
cnt:
	.space 400020
	.globl	in
	.align 64
in:
	.space 2400120
	.globl	b
	.align 64
b:
	.space 400020
	.globl	n
	.align 4
n:
	.space 4
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef

)");